inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����������ϱ������������ţ�������ӯ�ţ�����ǰ����
��Ѳʱ���ߵĵ��������޵��Ǹ���ƽ�����ֵ����ߵĵ��̲��ϡ�
���߹�ȥ��Զ�����Ǵ�����¡������Ƿ�����
LONG);
        set("outdoors", "kaifeng");
        set("exits", ([
        "east":__DIR__"fanta",
  		"north" : __DIR__"jiedao1",
  		"south" : __DIR__"nanying",
	]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
