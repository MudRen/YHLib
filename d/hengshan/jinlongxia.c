inherit ROOM;

void create()
{
	set("short", "����Ͽ");
	set("long", @LONG
����Ͽ�ֳ��������ǽ����ɽ����ڡ���ɽһ��̫��ɽ��
���������������еı�����������֮Ϊ������С���졹������
ب���������һ���н��еĶ��У�������Ϊ��ɽ���������
̩ɽ��������ɽ��������ɽ���Ժͺ�ɽ��ɡ�
LONG);
	set("exits", ([
		"southeast" : __DIR__"cuipinggu1",
		"northeast" : "/d/beijing/road6",
	]));
	set("objects", ([
		__DIR__"npc/jing" : 1,
		"/d/motianya/npc/qiaofu" : 1,
	]));
	set("outdoors", "hengshan");
	setup();
        replace_program(ROOM);
}

