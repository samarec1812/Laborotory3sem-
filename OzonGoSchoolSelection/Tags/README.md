# Tags

В базе данных имеется таблица с товарами goods (id INTEGER, name TEXT), таблица с тегами tags (id INTEGER, name TEXT) и таблица связки товаров и тегов tags_goods (tag_id INTEGER, goods_id INTEGER, UNIQUE (tag_id, goods_id)).

Выведите id и названия всех товаров, которые имеют все возможные теги в этой базе.

БД - SQLite3. В качестве языка решения выберите make2.


#### Формат ввода:
- SQL-запрос.
