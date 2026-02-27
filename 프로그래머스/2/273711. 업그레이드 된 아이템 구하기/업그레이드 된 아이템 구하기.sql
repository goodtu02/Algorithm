select i.item_id, i.item_name, i.rarity
from item_info as i, item_tree as t
where i.item_id = t.item_id and i.item_id in (select item_id
                    from item_tree
                    where parent_item_id in (select item_id
                                            from item_info
                                            where rarity = "RARE"))
order by i.item_id desc