#include <iostream>
#include <string>
#include <cstdint>
#include <cmath>
#include <vector>
#include <algorithm>

int xorAllNums(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> nums3(nums1.size() * nums2.size());
    for (int i = 0; i < nums1.size(); ++i) {
        for (int j = 0; j < nums2.size(); ++j) {
            nums3[i+j] = nums1[i] ^ nums2[j];
        }
    }
    int res = nums3[0] ^ nums3[1];
    for (int k = 2; k < nums3.size(); ++k) {
        res = res ^ nums3[k];
    }
    return res;

}

uint32_t reverseBits(uint32_t n) {
    int j = 31;
    for (int i = 0; i < j; ++i, --j) {
        uint32_t temp_i = (n >> i)&1;
        uint32_t temp_j = (n >> j)&1;
        // n = (n & ~((uint32_t)1 << i)) | (((n >> j)&1) << i);
        // n = (n & ~((uint32_t)1 << j)) | (((n >> i)&1) << j);
        n = (n & ~((uint32_t)1 << i)) | (temp_j << i);
        n = (n & ~((uint32_t)1 << j)) | (temp_i << j);
    }
    return n;
}

int hammingDistance(int x, int y) {
    int count = 0;
    while (x != 0 && y != 0) {
        if (x&1 ^ y&1) {
            ++count;
        }
        x >>= 1;
        y >>= 1;
    }
    return count;
}

bool hasAlternatingBits(int n) {
    while (n) {
        if (n&1 == (n >> 1)&1) {
            return false;
        }
        n >>= 1;
    }
    return true;
}

int findMSBPos(int n) {
    for (int i = 0; 1 << i < n; ++i) {
        if ((n >> i)&1 && ((n >> i + 1) == 0)) {
            return i;
        }
    }
    return 0;
}

int findMSBValue(int n) {
    for (int i = 0; 1 << i < n; ++i) {
        if ((n >> i)&1 && ((n >> i + 1) == 0)) {
            return 1 << i;
        }
    }
    return 0;
}

int findComplement(int num) {
    int msb = 0;
    int tmp = num;
    while (tmp >>= 1) {
        ++msb;
    }
    return (num ^ ((1 << (msb + 1)) - 1));
}

std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        int n = nums.size() - 1;
        int mask = (1 << nums.size()) - 1;
        std::vector<std::vector<int>> ans{std::vector<int>{}};
        while (mask) {
            int tempMask = mask;
            std::vector<int> tempVec;
            int i = 0;
            while (tempMask != 0) {
                if (tempMask&1) {
                    tempVec.push_back(nums[n - i]);
                }
                tempMask >> 1;
                i++;
            }
            ans.push_back(tempVec);
            mask--;
        }
        return ans;
}

void weirdAlgorithmCSES() {
    long long n;
    std::cin >> n;
    std::string res = std::to_string(n) + " ";
    while (n != 1) {
        if (n%2 == 0) {
            n /= 2;
            res += std::to_string(n) + " ";
        } else {
            n = (n * 3) + 1;
            res += std::to_string(n) + " ";
        }
    }
    std::cout << res;
}

void missingNumberCSES() {
    long long n;
    std::cin >> n;
    long long input;
    std::vector<long long> v;
    while (std::cin >> input) {
        v.push_back(input);
    }
    if (n == 2) {
        if (v[0] == 1) {
            n = 2;
        } else {
            n = 1;
        }
    } else {
        std::sort(v.begin(), v.end());
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] != v[i - 1] + 1) {
                n = v[i-1] + 1;
                break;
            }
        }
    }
    std::cout << n;
    return;
}

void repetitionsCSES() {
    std::string input;
    std::cin >> input;
    if (input.size() < 2) {
        std::cout << 1;
        return;
    }
    unsigned int res = 1;
    unsigned int counter = 1;
    for (unsigned int i = 1; i < input.size(); ++i) {
        if (input[i - 1] == input[i]) {
            ++counter;
        } else {
            if (counter > res) {
                res = counter;
                counter = 1;
            } else {
                counter = 1;
            }
        }
    }
    if (counter > res) {
        res = counter;
    }
    std::cout << res;
    return;
}

void increasingArray() {
    int vSize;
    std::cin >> vSize;
    long long input;
    std::vector<long long> v;
    while (std::cin >> input) {
        v.push_back(input);
    }
    long long moves = 0;
    for (int i = 1; i < vSize; ++i) {
        if (v[i - 1] > v[i]) {
            int temp = std::abs(v[i-1] - v[i]);
            if (temp > moves) {
                moves = temp;
            }
        }
    }
    std::cout << moves;
}

int main() {
    return 0;
}

// fucked up reverseBits() case, don't delete
    // std::cout << std::bitset<32>(4294967293) << std::endl;
    // std::cout << std::bitset<32>(reverseBits(4294967293)) << std::endl;