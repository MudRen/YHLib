// File(/data/room/shaqian/xiaoyuan.c) of shaqian's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "СԺСԺ");
	set ("long", @LONG
������һ�����ķ�����Ժ�ӣ�Ժǽ�����ú�ש���ɣ�����ߣ���
�Ƿǳ���ˬ���䡣Ժ�м��ù�ľ������Ȼ��һ��������Դ�ĸо���
Ժ��������Լ����ʯ�ٵ���Ժ�ӵı�����һ��ľ�š� 
LONG );

        set("room_key", "1 of shaqian");
	setup();

	set("exits", ([
                "out"    : "/d/suzhou/road1",
	]));

        set("outdoors", "suzhou");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dating",
        ]));
    
        set("room_owner", "ɱǮ");
        set("room_name", "СԺ");
        set("room_OWNER_ID", "shaqian");
        set("room_id", "xyuan");
        set("room_position", "��ʯ�ٵ�");
}
