inherit ROOM;

void create()
{
        set("short", "����� ");
        set("long", @LONG
���⸮���������Ҫ��ͨҪ�����ֵ����ߵ�������������
���������̷���ߺ�ȣ�������С�����ּۻ��ۣ������ޱȡ���
�߲�Զ��������ۡ���������ͤ԰��
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
  		"south" : __DIR__"wroad2",
  		"east" : __DIR__"tinyuan",
	]));
        set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
