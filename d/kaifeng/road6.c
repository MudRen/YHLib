inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǻ�Ὺ�����Ҫ�ֵ���Ҳ�ǻ��ϳ�Ѳ��Ҫ�����ֵ�
���ߵ���̨ͤ���ϣ�С����������������������������һ�ɷ�
��������һ���ߵ��������������Ŀ���������
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"east" : __DIR__"jieying",
  		"south" : __DIR__"road5",
  		"north" : __DIR__"xuandemen",
	]));
        set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
