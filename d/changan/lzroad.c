inherit ROOM;

void create()
{
        set("short", "��·");
        set("long", @LONG
����һ�����������·������̫������һ����į�ĸо���·
������ɢɢ�ķֲ��ż�ƬС��أ�żȻҲ�ܿ��ü�һЩ���̡�����
һƬ�Ļļš�
LONG);
        set("exits",  ([
                "west" : "/d/lanzhou/dongmen",
                "east" : __DIR__"tulu2",
        ]));
        set("outdoors", "lanzhou");
        setup();
        replace_program(ROOM);
}
