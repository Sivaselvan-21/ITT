
//happy number
class Solution {
    public boolean isHappy(int n) {
        int sum = 0;
        while (n != 0) {
            int n1 = n % 10;
            sum += n1 * n1;
            n = n / 10;
            
            if (n == 0) {
                if (sum == 1 || sum == 7) {
                    return true;
                }
                if (sum < 10) {
                    return false;
                }
                n = sum;
                sum = 0;
            }
        }
        return false;
    }
}
