class Solution:
    def calPoints(self, ops):
        i = 1
        history = []
        for s in ops:
            if s not in ("C", "D", "+"):
                curr_score = int(s)
            elif s == "C":
                history.pop()
            elif s == "D":
                curr_score = history[-1] * 2
            elif s == "+":
                curr_score = history[-1] + history[-2]
            if s != 'C':
                history.append(curr_score)
            i += 1
        return sum(history)


if __name__ == "__main__":
    scores = ["5","-2","4","C","D","9","+","+"]
    s = Solution()
    print(s.calPoints(scores))