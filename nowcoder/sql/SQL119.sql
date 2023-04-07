alter table user_info add column school varchar(15) after level;
alter table user_info change job profession varchar(10);
alter table user_info modify achievement int(11) default 0;
