
# 3321. The Knapsack Problem
# 
# Problem code: KNAPSACK
# 
# The famous knapsack problem. You are packing for a vacation on the sea side and you are going to carry only one bag with capacity S (1 <= S <= 2000). 
#You also have N (1<= N <= 2000) items that you might want to take with you to the sea side. Unfortunately you can not fit all of them in the knapsack 
#so you will have to choose. For each item you are given its size and its value. You want to maximize the total value of all the items you are going to 
#bring. What is this maximum total value?
# 
# Input
# 
# On the first line you are given S and N. N lines follow with two integers on each line describing one of your items. The first number is the size of 
#the item and the next is the value of the item.
# 
# Output
# 
# You should output a single integer on one like - the total maximum value from the best choice of items for your trip.
# 
# Example
# 
# Input:
# 4 5
# 1 8
# 2 4
# 3 0
# 2 5
# 2 3
# 
# 
# Output:
# 13

#SOLVING
#define what is a item
class Item
  attr_accessor :size, :value
  
  def initialize(size,value)
    self.size, self.value = size, value
  end
  
end

#testing 
bagSize = 4
items = [] 
i1 = Item.new(1,8)
i2 = Item.new(2,4)
i3 = Item.new(3,0)
i4 = Item.new(2,5)
i5 = Item.new(2,3)
items = [i1, i2, i3, i4, i5]

# #spoj
# inputs = gets.chomp.split(" ")
# bagSize = inputs[0].to_i #spoj
# 
# numberOfItems = inputs[1].to_i #spoj
# 
# items = []
# (1..numberOfItems).each do
#   inputs = gets.chomp.split(" ")
#   size = inputs[0].to_i
#   value = inputs[1].to_i 
#   items << Item.new(size,value)
# end

# # Second Internet Solution with Dynamic Programing
# Setting matrix 
valueMatrix = []
(0..items.length).each do |i|
  valueMatrix << []
  (0..bagSize).each do |j|
    valueMatrix[i] << nil
  end
end

(0..items.length).each do |i|
  (0..bagSize).each do |j|
    if i == 0 #To NONE line in the matrix
      valueMatrix[i][j] = 0 #Put zero for the first line of the valueMatrix
    else
      if items[i-1].size <= j #Check if the item fit on it`s on
        if valueMatrix[i-1][j] >= valueMatrix[i-1][j-items[i-1].size] + items[i-1].value
          valueMatrix[i][j] = valueMatrix[i-1][j]
        else
          valueMatrix[i][j] = valueMatrix[i-1][j-items[i-1].size] + items[i-1].value
        end
      else
        valueMatrix[i][j] = valueMatrix[i-1][j]
      end 
    end
  end
end

p "                      0  1  2  3  4"
valueMatrix.each_index do |i|
  if i == 0
    p "                NONE #{valueMatrix[i]}"
  else
    p "Valeu : #{items[i - 1].value} Weight : #{items[i - 1].size} #{valueMatrix[i]}"
  end
end

# p occupation






