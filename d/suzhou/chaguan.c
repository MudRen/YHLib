inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
���һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ��
���Ű�����һ���ſ��������˿��ˣ������̸Ц����ͷ�Ӷ���
����������һ���ź��ſ����ǣ���̨������һλ�ϰ����
�ڵ������̡�
LONG );
	set("resource/water", 1);
	set("exits", ([
		"west" : __DIR__"nandajie3",
	]));
	set("objects", ([
		__DIR__"npc/lady2" : 1,
	]));
	setup();
	replace_program(ROOM);
}

