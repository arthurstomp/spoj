## Testing knapsack
require_relative 'knapsack'

bagSize = 6

# creating items
item1 = Item.new(2,10)# standard item
item2 = Item.new(4,20)# large and expensive item
item3 = Item.new(1,5)# small and cheap item
item4 = Item.new(1,20)# small and expensive item
item5 = Item.new(4,5)# large and cheap item
itemLargerThanTheBag = Item.new(bagSize + 1,10)

# x = [item1, item2, item3, item4, item5]
# x.sort!{|x,y|y.value <=> x.value}
# p x


#creating bag
bag = Bag.new(bagSize)

#adding item 
if bag.put(item1)
  p "last putted item #{bag.items.last}"
else
  raise "Something is wrong with put method"
end

#dropping item
if droppedItem = bag.drop
  p "dropped item #{droppedItem}"
else
  raise "Something is wrong with drop method"
end

#put items in order by of value
bag.put(item2)
bag.put(item1)
lastItem = bag.items.last
firstItem = bag.items.first
if firstItem.value >= lastItem.value
  p "First item value = #{firstItem.value}, last item value = #{lastItem.value}"
else
  raise "Something is wrong with put method. They arent in the right order"
end

#try to put a item that don't fit
bag.put(item3)
if item3 != bag.items.last
  p "the item #{item3} can not be placed"
else
  raise "Something is wrong with put method. The item dont fit but was put"
end