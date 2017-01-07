''' Buddy system bitmap
    Given a complete binary tree with nodes of values of either 1 or 0, the following rules always hold:
    (1) a node's value is 1 if and only if all its subtree nodes' values are 1
    (2) a leaf node can have value either 1 or 0
    Implement the following 2 APIs:
    set_bit(offset, length), set the bits at range from offset to offset+length-1
    clear_bit(offset, length), clear the bits at range from offset to offset+length-1
    
    i.e. The tree is like:
                 0
              /     \
             0        1
           /  \      /  \
          1    0    1    1
         /\   / \   / 
        1  1 1   0 1
        Since it's complete binary tree, the nodes can be stored in an array:
        [0,0,1,1,0,1,1,1,1,1,0,1] 
        
'''

class Bitmap:
  def __init__(self, A):
    self.original = A
    self.data = list(self.original)

  def reset(self):
    self.data = list(self.original)

  def update_from(self, i):
    if i >= len(self.data): return
    if self.data[i] == 1: return
    self.data[i] = 1
    self.update_from(2*i+1)
    self.update_from(2*i+2)

  def set_bit(self, offset, length):
    """
    Set bits from offset to offset+length-1 to 1
    """
    n = len(self.data)
    for i in range(offset, min(n, offset+length)):
      if self.data[i] == 1: #no need to update
        continue
      self.update_from(i)
      # update ancestors
      j = i
      while j > 0:
        if (j%2==0 and self.data[j-1] == 1) or \
           (j%2 == 1 and j < n-1 and self.data[j+1] == 1):
          self.data[(j-1)/2] = 1
          j = (j-1)/2
        else: break

  def clear_bit(self, offset, length):
    """
    Set bits from offset to offset+length-1 to 0
    """
    n = len(self.data)
    for i in range(offset, min(n, offset+length)):
      if self.data[i] == 0: #no need to update
        continue
      self.data[i] = 0
      # if decendants are out of update range and both are one
      # clear the left child
      j = 2*i + 1
      if j >= offset+length and j < n and self.data[j] == 1 and \
         ((j+1 >= n) or (j+1 < n and self.data[j+1] == 1)):
         self.data[j] = 0
         j = 2*j + 1
      # clear ancestors
      j = (i-1)/2
      while j > 0:
        if self.data[j] == 0: break
        self.data[j] = 0
        j = (j-1)/2



A=[0,0,1,1,0,1,1,1,1,1,0,1]
m = Bitmap(A)
test_cases = [(x,y) for x in range(len(A)) for y in range(1,len(A)-x+1)]
 
for t in test_cases:
  pos, length = t       
  m.reset()
  m.set_bit(pos, length)
  print 'after setting bit from ', pos, 'for ', length, 'A is: ', m.data
  m.reset()
  m.clear_bit(pos, length)
  print 'after clearing bit from ', pos, 'for ', length, 'A is: ', m.data
