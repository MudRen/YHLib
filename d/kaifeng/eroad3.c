inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
������ǿ��⸮�ڶ���������Ҫͨ������·�����˵��̸�
�ڲ��ϡ��������ƣ��۹�ģ�������ģ��ʽ���ģ���������
���ѵģ��ϱ߲�Զ����ɽ�¸ʻ�ݡ������ǿ���������������
���������µĺ컨����ܶ����ڡ�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"south" : __DIR__"eroad2",
  		"west" : __DIR__"tieta",
  		"east" : __DIR__"hh_qguangchang",
	]));
        set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
