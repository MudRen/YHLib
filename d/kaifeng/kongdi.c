inherit ROOM;

void create()
{
        set("short", "�յ�");
        set("long", @LONG
����԰�Ĳ˵��м��һƬ�յأ���������Ϊԭ���Ĳ˵ر�
��ƽ��ɮ�˲��ͷ����ֶ��������ġ����ص��м�һס�ϻ���
֦Ҷ�����ģ��������ѻ��ʱ���С��ϱ��Ǹ�С��ѣ�������
��С�ü䡣
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"west" : __DIR__"caidi5",
  		"south" : __DIR__"fenjiao",
  		"east" : __DIR__"tangjian",
	]));
        set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
