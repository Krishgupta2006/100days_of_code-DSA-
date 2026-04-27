 #include <stdio.h>

int integerSquareRoot(int n) {
    int low = 0, high = n;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // To avoid overflow, use long long
        long long square = (long long)mid * mid;

        if (square == n) {
            return mid;
        } else if (square < n) {
            ans = mid;      // store possible answer
            low = mid + 1;  // search right
        } else {
            high = mid - 1; // search left
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", integerSquareRoot(n));

    return 0;
}   