inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG 
���ǳ���ѧ�ķ��䡣����ѧ�����λʦ��һ�����ɰ����ڴ�
ʦ���գ�������λʦ�ֵ��У����Ͱ����ڹ�ϵ��á�ͬʱ��Ϊ��
���������ϲ�������ð��������Σ����԰�������ʧ����ǰ����
�����ǵĺ����ƽ��������ܡ��������������ţ�ֻ�����Ϸ���
һ��δд��Ĳ���
LONG);
        set("exits", ([
            	"south"  : __DIR__"zoulang4", 
        ]));
        set("objects", ([  
                __DIR__"npc/cheng" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

