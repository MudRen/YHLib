inherit ROOM;

void create()
{
        set("short", "��ׯ����");
        set("long", @LONG
��������ׯ�����������õ���Ϊ���ţ�˿��û�������ϵ�
�������ա�һ�ź�ľ���������и���񣬹�����˸�ʽ������
�顣����ؤ�����ؤΧ�������
LONG);
        set("exits", ([
                "west"  : __DIR__"ma_zhengting",
        ]));
        set("objects", ([
		"/d/gaibang/npc/5dai" : 1,
		"/d/gaibang/npc/6dai" : 1,
		"/d/gaibang/npc/7dai" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
