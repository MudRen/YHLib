inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
��Ժ֮���������ơ������ľ������ʯ�ʣ�������Ϣ����
�е�һ��������¯��������������Ը�����Ƕ����ڴ˿�ͷ����
���ǲؾ�¥��������ǧ��ǧ�۷������ǰ˱������
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"west" : __DIR__"qianshou",
  		"east" : __DIR__"cangjing",
  		"north" : __DIR__"8bao",
  		"south" : __DIR__"daxiong",
	]));
        set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
