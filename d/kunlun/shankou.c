inherit ROOM;

void create()
{
	set("short", "����ɽ���");
        set("long", @long
����λ����ɽ֮���һ��Сɽ�ڡ�ֻ������ɽ������ǧ�
Ⱥɽ������ɽ�ϵ���ľ�����࣬����ʱ¶����ͺͺ��ɽ���ʯ
ͷ��ɽ�����Ͼ�Ϊ��ѩ���ǣ��������ţ��߲�������
long);
	set("exits",([
		"west" : __DIR__"klshanlu",
		"southeast" : __DIR__"kekexili",
	]));

	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}
