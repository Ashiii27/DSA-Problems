class Solution:
    def cntSetBits(self, num):
        return bin(num).count('1')

    def formatTime(self, h, m):
        formattedTime = str(h) + ":"
        if m < 10:
            formattedTime += "0"
        formattedTime += str(m)
        return formattedTime

    def readBinaryWatch(self, turnedOn):
        times = []
        for h in range(12):
            for m in range(60):
                if self.cntSetBits(h) + self.cntSetBits(m) == turnedOn:
                    times.append(self.formatTime(h, m))
        return times