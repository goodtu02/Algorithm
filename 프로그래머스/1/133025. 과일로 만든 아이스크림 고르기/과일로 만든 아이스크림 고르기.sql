-- 코드를 입력하세요
SELECT FLAVOR
from FIRST_HALF
where TOTAL_ORDER > 3000 and FLAVOR in (select FLAVOR 
                                        from ICECREAM_INFO 
                                        where INGREDIENT_TYPE LIKE 'fruit%')
order by TOTAL_ORDER desc;