create table if not exists user_info_vip (
    id int(11) primary key auto_increment comment "自增ID",
    uid int(11) unique not null comment "用户ID",
    nick_name varchar(64) comment "昵称",
    achievement int(11) default 0 comment "成就值",
    level int(11) comment "用户等级",
    job varchar(32) comment "职业方向",
    register_time datetime default current_timestamp comment "注册时间"
)default charset=utf8;
