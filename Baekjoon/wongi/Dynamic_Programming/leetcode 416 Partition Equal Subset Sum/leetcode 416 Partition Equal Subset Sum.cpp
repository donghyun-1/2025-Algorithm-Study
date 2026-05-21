/*
원소의 합이 서로 같은 두 개의 부분 집합으로 분할할 수 있는지 여부 판단?
일단 모든 숫자들의 합이 홀수가 되면 두개의 배열로 나누는 것이 불가능 -> 홀수 일때 2로 나누면 두개의 값을 두개로 나눌수가 없죠?
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // bool answer=false;
        bool dp[201][20001] = { false };
        int numS = nums.size();
        //i번째까지 왔을 때 j의 값을 만들 수 있는가? 
        //nums[i]를 쓰거나 안쓰거나 둘중 하나의경우가 있다?!!@!
        /*
            nums[0]~ nums[i]까지 봤을때 일부 숫자를 골라서 합 j를 만들수 있으면 true

        */
        int sum = 0;
        for (int i = 0; i < numS; i++)
        {
            sum += nums[i];
        }
        int target = sum / 2;
        if (sum % 2 != 0)
        {
            return false;
            /*
            만일 이 전체 합이 홀수이면 두 부분 집합의 합을 같게 두개로 못나눔
            */
        }
        else
        {
            for (int i = 0; i < numS; i++)
            {
                dp[i][0] = true;
                //i번째 값을 가지고 0은 다 만들 수 있음
            }
            dp[0][nums[0]] = true;
            //첫번째 값을 사용해서 첫번째 자기 자신은 만들 수 있잖아?이를 생각해서 초기화
            for (int i = 1; i < numS; i++)
            {
                for (int j = 1; j <= target; j++)
                {
                    if (dp[i - 1][j])
                        //nums[i](현재 수를 안쓰는 경우? j를 만들 수 있음)
                        //그러면 이전숫자들로만 j를 만들 수 있어야ㅏㅎㅁ.
                    {
                        dp[i][j] = true;
                    }
                    else // nums[i]현재 수를 사용
                    {
                        if (j >= nums[i] && dp[i - 1][j - nums[i]])
                            //현재 nums가 타겟보다 작거나
                            //현재 i말고 이전에 숫자들로(num[0]~nums[i-1])이전 값(j-nums[i])을 만들수 있어야한다.
                        {
                            dp[i][j] = true;
                        }
                    }
                }
            }

        }

        if (dp[numS - 1][target])
        {
            return true;
        }
        else
        {
            return false;
        }

    }
};