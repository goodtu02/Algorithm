-- 코드를 입력하세요
SELECT i.animal_id, i.animal_type, i.name
from animal_ins as i, animal_outs as o
#i에서 intact, o에서 spayed and neutered
where i.animal_id = o.animal_id and 
i.sex_upon_intake like "Intact%" and
(o.sex_upon_outcome like "Spayed%" or
o.sex_upon_outcome like "Neutered%")
order by i.animal_id