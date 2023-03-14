#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

void bucketSort(std::vector<int>& nums, int range) {
    std::vector<std::vector<int>> buckets(range);

    for (int num : nums) {
        int bucket_idx = num / range;
        buckets[bucket_idx].push_back(num);
    }

    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
    }

    int i = 0;
    for (auto& bucket : buckets) {
        for (int num : bucket) {
            nums[i++] = num;
        }
    }
}

int main() {
    std::fstream input, output;
    input.open("input.txt", std::ios::in);
    output.open("output.txt", std::ios::out);
    if (!input.is_open()) {
        std::cout << "Nie udalo sie otworzyc pliku wejsciowego.\n";
        return 1;
    }

    std::vector<int> nums;
    int a;
    while (input >> a) {
        nums.push_back(a);
    }
    input.close();

    if (nums.empty()) {
        std::cout << "Plik wejsciowy jest pusty.\n";
        return 1;
    }

    int range = 10;
    bucketSort(nums, range);

    for (int num : nums) {
        output << num << " ";
    }
    output.close();

    return 0;
}