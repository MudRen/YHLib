inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����������˫��֮һ��������ķ��䡣������Ҳ���������
���ǵ�������ĺۼ�������˭���ⷢй��ŭ���Ƶġ�һ���ֳ�
����������һ�ۣ���ƫ�����ŭɫ���������ӣ�վ�����У�����
���⣬�����ؽ�ҧ,�������޺��¡�
LONG);
        set("exits", ([
            	"west" : __DIR__"houyuan2", 
        ]));
        set("objects", ([  
                __DIR__"npc/feng" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

