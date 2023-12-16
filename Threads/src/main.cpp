#include "Core.h"

#include <queue>
#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <chrono>

const int PRODUCER_GOODS_AMOUNT = 500;

int m_Counter = 0;
bool m_Done = false;
std::queue<int> m_Goods;

std::mutex m_Mutex;
std::condition_variable m_Condition;

// Easy method for printing a gui header to the console.
inline void DisplayHeader(const std::string& header)
{
    std::cout << GUI::CreateHeader(header, Colour::Background::Green) << std::endl;
}

// Easy method for printing a gui sub header to the console.
inline void DisplaySubHeader(const std::string& header)
{
    std::cout << GUI::CreateHeader(header, Colour::Background::Blue, 1) << std::endl;
}

// Easy method for printing to the console.
inline void PrintLine(const std::string& body = "")
{
    std::cout << body << std::endl;
}

// Producer function to add goods to the queue.
void producer()
{
    PrintLine("1. Starting producer...");

    // Produce goods and update the counter.
    for (int i = 0; i < PRODUCER_GOODS_AMOUNT; ++i)
    {
        {
            // Lock the mutex to ensure exclusive access to the goods vector.
            std::lock_guard<std::mutex> lock(m_Mutex);
            m_Goods.push(i);
            m_Counter++;
        }

        // Notify the consumer that new goods are available.
        m_Condition.notify_one();
    }

    // Notify the consumer that the producer is done producing goods.
    m_Done = true;
    m_Condition.notify_one();

    PrintLine("3. Finished producer...");
}

// Consumer function to consume goods from the queue.
void consumer()
{
    PrintLine("2. Starting consumer...");

    // Continue consuming goods until the producer is done and the queue is empty.
    while (!m_Done || !m_Goods.empty())
    {
        // Lock the mutex and wait for goods to be available or for the producer to be done.
        std::unique_lock<std::mutex> lock(m_Mutex);
        m_Condition.wait(lock, [&]() { return !m_Goods.empty() || m_Done; });

        // Break the loop if the producer is done and the queue is empty.
        if (m_Done && m_Goods.empty())
            break;

        // Consume the goods and update the counter.
        m_Goods.pop();
        m_Counter--;
    }

    PrintLine("4. Finished consumer...");
}

int main()
{
    DisplayHeader(" PRODUCER CONSUMER ");

    // Record the starting time for performance measurement.
    auto startTime = std::chrono::high_resolution_clock::now();

    m_Counter = 0;

    // Create producer and consumer threads.
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    // Wait for threads to finish execution.
    producerThread.join();
    consumerThread.join();

    // Calculate the execution time of the process.
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    PrintLine();

    DisplaySubHeader("RESULTS");
    PrintLine(GUI::CreateHeader("Produced goods: " + std::to_string(PRODUCER_GOODS_AMOUNT) + " | " + "Net should be 0.", 2));
    PrintLine(GUI::CreateHeader("Net: " + std::to_string(m_Counter) + " | " + "Goods array size: " + std::to_string(m_Goods.size()), 2));
    PrintLine(GUI::CreateHeader("Execution time: " + std::to_string(duration.count()) + " milliseconds", 2));

    return 0;
}
