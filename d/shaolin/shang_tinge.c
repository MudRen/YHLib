inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
ƫ�����õ���Ϊ���ţ�˿��û�������ϵ��������ա�һ�ź�
ľ���������и���񣬹�����˸�ʽ�������顣ǽ�Ϲ��ż�����
��������������ʱ�������ֿ��Ե��鷿�á�
LONG);
	set("exits", ([
		"west"  : __DIR__"shang_dating",
	]));
	setup();
	replace_program(ROOM);
}
