inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
������÷ׯ�����������۵�ʱ����Ϣ�ĵط������ﾭ��������
�����׵�����������򵥵ķ��ż��ŵ��ӣ������ޱ���������ͷ����
��÷ׯ������Ȼ������ɨ�����������Ȼ���Ҳ������ܶ�÷ׯ����
һ�������ͷ��˯�����ǹ���ƣ�͵�Ե�ʡ� 
LONG
        );
        set("sleep_room", 1);
        set("exits", ([
            "west" : __DIR__"zoulang2",
        ]));
        set("no_fight", 1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
