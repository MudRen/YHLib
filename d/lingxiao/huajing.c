inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG 
����һ�������˸�ɫ÷���Ļ�����С������÷��Ʈ�㣬÷
����������Ȼ���ͼ���÷֦���ѣ�÷����᫣�����Ʈ�ݣ����
��֮��÷֦���Կݲг�׾Ϊ��÷��÷���Է���Ũ��Ϊ�У���
��֮������ν���ӡ�
LONG);
        set("outdoors", "lingxiao");
        set("exits", ([
            	"east"  : __DIR__"qianyuan",
            	"up"  : __DIR__"feihua",  
        ]));
        set("objects", ([
               "/clone/quarry/he2" : 1,
               __DIR__"obj/mei" : 4,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

