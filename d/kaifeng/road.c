inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����������ϱ������������ţ�������ӯ�ţ�����ǰ����
��Ѳʱ���ߵĵ������޵�Ҳ�Ǹ���ƽ���������ߵ��̲��ϡ���
���ٹ�ȥ��Զ������ʯ���ž�������£���������ȸ�š�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"west" : __DIR__"yaopu",
  		"southup" : __DIR__"gongmen",
  		"north" : __DIR__"zhuque",
	]));
        set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
