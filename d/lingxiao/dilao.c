inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������ڼ����������棬��ȴ�е���������͸�롣������
�䣬һ����Ӱ�ֳ���������Ȼվ��ʯ���ԡ��չ�͸��������ֻ��
�����������׺�����Ŀ��࣬����΢�����������ССʯ��װ��
��������������Ƶģ��۹�ҫ�����磬������ٱ�� 
LONG );
        set("no_clean_up", 0);
        set("exits", ([
                "out" : __DIR__"didi",
        ]));
        set("objects", ([
                CLASS_D("lingxiao") + "/baizizai" : 1,
        ]));

        setup(); 
        replace_program(ROOM);
}

