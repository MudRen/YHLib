inherit ROOM;

void create()
{
        set("short", "Сé��");
        set("long", @LONG
���߽������е�Сé�ݣ�������һ�£���é�ݽ�����é��
�������ıߵ�ǽ������һ������ë�������¶��ɵģ����е�
����Ҳ���Ǵ������ƣ����ϷŵĲ���������������ɵġ�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
		"out" : __DIR__"zhulin",
	]));

        setup();
        replace_program(ROOM);
}
