// File(/data/room/liujie/xiaoyuan.c) of liujie's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "������СԺ");
	set ("long", @LONG
������һ�����ķ�����Ժ�ӣ�Ժǽ�����ú�ש���ɣ�����ߣ���
�Ƿǳ���ˬ���䡣Ժ�м��ù�ľ������Ȼ��һ��������Դ�ĸо���
Ժ��������Լ����ʯ�ٵ���Ժ�ӵı�����һ��ľ�š� 
LONG );

        set("room_key", "1 of liujie");
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
    
        set("room_owner", "��ȥ");
        set("room_name", "������");
        set("room_OWNER_ID", "liujie");
        set("room_id", "tingyu");
        set("room_position", "��ʯ�ٵ�");
}
