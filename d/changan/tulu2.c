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
                "northup"   : __DIR__"tulu3",
                "southwest" : __DIR__"tulu1",
                "west" : __DIR__"lzroad",
        ]));
        set("outdoors", "changan");
        setup();
        replace_program(ROOM);
}
