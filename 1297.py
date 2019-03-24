import math
shift,height_portion,width_portion=input().split()
shift=int(shift)
height_portion=int(height_portion)
width_portion=int(width_portion)
shift=shift*shift
sum=height_portion*height_portion+width_portion*width_portion
sum=shift/sum
sum=math.sqrt(sum)
print(int(sum*height_portion),int(sum*width_portion))
