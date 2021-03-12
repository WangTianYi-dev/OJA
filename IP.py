import sys

# 读入数据
def FUNC(N):
    ips = []
    while N > 0:
        K = input()
        ips.append(K)
        N -= 1
    
    # for ip in ips:
    #     print(ip)
    # 将十进制ip翻译为二进制
    bits = []
    for s in ips:
        l = s.split('.')
        res = ""
        for i in l:
            num = int(i)
            #
            # print(num, end=' ')
            bi = ""
            cnt = 0
            while num > 0:
                d = num % 2
                bi = str(d) + bi
                num >>= 1
                cnt += 1
            while cnt < 8:
                bi = '0' + bi
                cnt += 1
            # print(bi)
            res += bi
        bits.append(res)

    # for s in bits:
    #     print(s)

    # 数相同的位数


    def f(bits):
        for i in range(len(bits[0])):
            t = bits[0][i]
            for s in bits:
                if s[i] != t:
                    return i
        return 32

    # print(f(bits))


    def getIP(IP):
        s = ""
        for i in range(4):
            ts = IP[i * 8: (i+1) * 8]
            tint = int(ts,base=2)
            if i != 0:
                s += '.'
            s += str(tint)        
        return s

    # 转换成ip地址和子网掩码
    slen = f(bits)
    mask = '1' * (slen) + '0' * (32 - slen)
    # print(mask)
    tlen = slen
    i = 0
    addresses = bits[0][0:slen]
    while tlen < 32:
        addresses = addresses + '0'
        tlen += 1


    print(getIP(addresses))
    print(getIP(mask))
    # for i in addresses:

while True:
    line = sys.stdin.readline()
    if not line:
        break
    N = int(line)
    FUNC(N)