inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
��ط����Ǹ����ľ������������Ʒ��Ȼ�����˲�֪��
�����£�������Ȼ��á�������һ˫Ů�˵Ļ�Ь��ɫ������
��Ϊ���ޣ���������ϸ������֪���ּ��ʱ��Ϊ�ҳ������ɵ�
����һ������
LONG);

	set("exits", ([
		"south" : __DIR__"feixu2",
	]));

	setup();
	replace_program(ROOM);
}
