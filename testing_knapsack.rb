## Testing knapsack
p require_relative 'knapsack'

bagSize = 5

# creating items
item1 = Item.new(2,10)# standard item
item2 = Item.new(4,20)# large and expensive item
item3 = Item.new(1,5)# small and cheap item
item4 = Item.new(1,20)# small and expensive item
item5 = Item.new(4,5)# large and cheap item
itemLargerThanTheBag = Item.new(bagSize + 1,10)

#creating bag
bag = Bag.new(bagSize)

#adding item 
if bag.put(item1)
  p bag.items.last
else
  raise "Something is wrong on put method"
end

