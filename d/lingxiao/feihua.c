inherit ROOM;

void create()
{
        set("short","�ɻ���");
        set("long",@LONG 
���������ǵ��������ӣ�����÷Ů���������ϵľ�����¥��
�ɻ��󡣻�����������������������Ψһ��Ů�ԣ�һ����Ϊ���ӣ�
���������ϱ�����ϲ�徻����һ�˶����ڴˡ��˴��ǻ�԰С¥֮
�ϣ�ƾ��������ǧ���÷��ӭѩ���裬��÷Ʈ�㣬�׷׶��¡���
�Ϸ���һ��������ɫ��÷����
LONG);
        set("outdoors", "lingxiao");
        set("exits",([
            "down"  : __DIR__"huajing",  
        ]));
        set("objects", ([
                CLASS_D("lingxiao") + "/huawanzi" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

