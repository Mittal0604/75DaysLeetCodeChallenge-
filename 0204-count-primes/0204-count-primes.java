class Solution {
    static boolean[] arr;
    public int countPrimes(int n) {
        if (arr == null) {
            int max = 5000000;
            arr = new boolean[max];
            Arrays.fill(arr,true);
            arr[0] = arr[1] = false;
            for (int i = 2;i*i<max;i++) {
                if (!arr[i]) continue;
                for (int j = i*i;j<max;j+=i) {
                    arr[j] = false;
                }
            }
        }
        int count = 0;
        for (int i = 0;i<n;i++) {
            if (arr[i]) count++;
        }
        return count;
    }
}