inherit ROOM;

void create()
{
        set("short","����");
        set("long",@LONG
�����������ǵĸ���֮һ������������������һ����ͷ��
�Եز�֪�ڸ�ʲô���������ģ�׼ûʲô���¡������������
��̫ƽ���鷳����Ҳͦ��ģ���������Ϊ�
LONG);
        set("exits",([
            	"east"  : __DIR__"lianwu2",
            	"west"  : __DIR__"dadian",
        ]));
        set("objects", ([
               __DIR__"npc/dizi" : 3,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

