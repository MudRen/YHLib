// Room: /u/zqb/tiezhang/pubu.c

inherit ROOM;

void create()
{
	set("short", "�ٲ�");
	set("long", @LONG
ɽ·�е��������Զ����������ˮ����ת��һ��ɽ����ֻ��һ������
�ƵĴ��ٲ��Ӷ���˫��֮�䱼�ڶ��£���ɽ�żţ���ˮ��������ɽ���м���
���죬�������Ǿ��ˡ�
LONG	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"xzfeng",
  "eastdown" : __DIR__"sblu-1",
]));
	set("no_clean_up", 0);

	setup();
}