SELECT i.INGREDIENT_TYPE , sum(f.TOTAL_ORDER) as TOTAL_ORDER
from first_half as f , icecream_info as i
where i.flavor = f.flavor
group by i.INGREDIENT_TYPE
order by sum(f.TOTAL_ORDER) asc