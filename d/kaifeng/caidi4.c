inherit ROOM;

void create()
{
        set("short", "�˵�");
        set("long", @LONG
��Ƭ��԰�Ӽ����������һЩʱ���߲ˡ������м���ľ׮
����Ĳ˼��ӣ���һЩ���ٵ��߲��������������Ŀ��ȥ����
���һƬ��԰�ӣ���Ȼ���������û�м��òˡ�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"north" : __DIR__"caidi",
  		"west" : __DIR__"caidi2",
	]));
        set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
