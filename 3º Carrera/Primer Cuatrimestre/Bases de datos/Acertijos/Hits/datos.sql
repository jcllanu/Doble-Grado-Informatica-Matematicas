
-- Datos: David Pérez Asensio
-- "With 50 million copies sold, not only is Bing Crosby's "White Christmas" the best-selling Christmas song of all time, it's also the best-selling single ever, according to Guinness World Records." (https://www.countryliving.com/life/news/a45720/white-christmas-song-history/)
-- 10/10/2015


CREATE TABLE hits (
  theme varchar(50) NOT NULL,
  copies int NOT NULL,
  PRIMARY KEY (theme, copies));

INSERT INTO hits (theme, copies) VALUES
('I Will Always Love You', 20),
('If I Didn''t Care', 19),
('In the Summertime', 31),
('It''s Now or Never', 20),
('My Heart will Go On', 25),
('Rock Around the Clock', 25),
('Silent Night', 30),
('We Are the World', 20),
('White Christmas', 50);


