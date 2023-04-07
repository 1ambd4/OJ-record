select quantity, item_price
from OrderItems
!-- order by quantity desc, item_price desc;
!-- 可以用序号表示select后的字段
order by 1 desc, 2 desc;
