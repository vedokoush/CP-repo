SEGMENT TREE

? khi nào cần dùng segmentree
-> khi cần tìm min, max, gcd, lcm trong đoạn a[l -> r]

Cập nhật mảng a vẫn tìm được kết quả -> log2(n)

a[2] = x (cập nhật điểm)
a[l -> r] = x (cập nhật đoạn)

chỉ trong log2(n)

>> Thay đổi 1 điểm

Tư tưởng segmenttree
    a: 2 3 2 4 4 2 3 4
               (1, 8)
      (1, 4)          (5, 8)
(1, 2)      (3, 4)