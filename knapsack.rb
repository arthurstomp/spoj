
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
#define what is a bag
class Bag
  attr_accessor :size, :items, :occupied, :value
  
  def initialize(size)
    self.size = size
    self.occupied = 0
    self.value = 0
    self.items = []
  end
  
  def empty?
    self.items.empty?
  end
  
  def full?
    self.occupied == self.size
  end
  
  def put(item)
    if item.size <= self.size - self.occupied
      self.items << item
      self.items.sort!{|x,y| y.value <=> x.value}
      self.occupied += item.size
      self.value += item.value
      return true
    else
      return false
    end
  end
  
  def drop
    lastItem = self.items.last
    self.occupied -= lastItem.size
    self.value -= lastItem.value
    self.items.pop
  end
  
end

# bagCapacity = gets.chomp #spoj
# bag = Bag.new(bagCapacity)
bag = Bag.new(rand(1..2000)) #testing

# numberOfitems = gets.chomp #spoj
numberOfItems = rand(1..20) #testing

items = []
(1..numberOfItems).each do
  # size = gets.chomp #spoj
  size = rand(1..2000) #testing
  # value = gets.chomp #spoj
  value = rand(1..2000) #testing 
  items << Item.new(size,value)
end

items.each do |item|
  if not bag.put(item) and not bag.empty?
    lastItem = bag.items.last
    
    p lastItem
    p bag.items.count
    
    if item.value > lastItem.value
      if lastItem.size >= item.size
        bag.drop
        bag.put(item)
      else
        sumValue = 0
        sumSize = 0
        nDrops = 0
        
        # while sumValue <= item.value and sumSize < item.size and if nDrops <= bag.items.count - 1 do
        #           auxItem = bag.items[bag.items.count - 1 - nDrops]
        #           sumValue += auxItem.value
        #           sumSize += auxItem.size
        #           nDrops += 1
        #         end
        
        (1..nDrops).each do
          bag.drop
        end
        
        bag.put(item)
        
      end
    end
    if item.value == lastItem.value and item.size < lastItem.size
      bag.drop
      bag.put(item)
    end
  end
end
# 
p bag.value







