inherit ROOM;

void create()
{
	set("short", "��н��");
	set("long", @LONG
��������ոս��ɲ��ã�һ�ж���ո�µģ����������������Ҳ�Ǹ�
�Ӿ��Ƕ����������ġ�����������С��������ɨ�أ���Ϊ������������
���ݵ��˺��١�
LONG);
	set("no_clean_up", 0);
	set("exits", ([
  		"west" : __DIR__"xiaoxiang2",
	]));
        set("objects", ([
                "/d/kaifeng/npc/oldwomen" : 1,
                "/d/kaifeng/npc/zhike" : 1,
                "/clone/npc/walker" : 1,
        ]));

	setup();
	replace_program(ROOM);
}
