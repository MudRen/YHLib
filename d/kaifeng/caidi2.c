inherit ROOM;

void create()
{
        set("short", "�˵�");
        set("long", @LONG
��Ƭ��԰�Ӽ����������һЩʱ���߲ˡ������м���ľ׮
����Ĳ˼��ӣ���һЩ���ٵ��߲��������������Ŀ��ȥ����
���һƬ��԰�ӣ���Ȼ���������û�м��òˡ�
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
		  "north" : __DIR__"zoulang2",
		  "east" : __DIR__"caidi4",
        ]));
        set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
