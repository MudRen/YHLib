inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǻ�Ὺ�����Ҫ�ֵ���Ҳ�ǻ��ϳ�Ѳ��Ҫ�����ֵ�
���ߵ���̨ͤ���ϣ�С����������������������������һ�ɷ�
�����ϱߵĸ��ž������ţ���������ͤ�¡�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"southup" : __DIR__"road4",
  		"north" : __DIR__"road6",
  		"west" : __DIR__"longting",
	]));
        set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
